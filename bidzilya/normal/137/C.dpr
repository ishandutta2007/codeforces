{$APPTYPE CONSOLE}

var
  i,n,r,ans:integer;
  a,b:array[-10..100000]of integer;

procedure s(l,r:integer);
var
  i,j,x,tmp:integer;
begin
  i:=l; j:=r; x:=a[(i+j)div 2];
  repeat
    while a[i]<x do
      inc(i);
    while a[j]>x do
      dec(j);
    if i<=j then
    begin
      tmp:=a[i];
      a[i]:=a[j];
      a[j]:=tmp;

      tmp:=b[i];
      b[i]:=b[j];
      b[j]:=tmp;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then
    s(i,r);
  if j>l then
    s(l,j);
end;

begin
  readln(n);
  for i:=1 to n do
    readln(a[i],b[i]);
  s(1,n);
  ans:=0;
  r:=b[1];
  for i:=2 to n do
    if b[i]<r then
      inc(ans)
    else
      r:=b[i];
  writeln(ans);
end.