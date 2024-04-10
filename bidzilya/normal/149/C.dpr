program task_3;

{$APPTYPE CONSOLE}

var n,i: integer;
    t,a: array[1..100000]of integer;

procedure qsort(l,r: integer);
var i,j,buf,x: integer;
begin
  i:=l;j:=r;x:=a[i+random(j-i+1)];
  repeat
    while (a[i]<x)do inc(i);
    while (a[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=a[i];a[i]:=a[j];a[j]:=buf;
      buf:=t[i];t[i]:=t[j];t[j]:=buf;
      inc(i);dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

begin
  read(n);
  for i:=1 to n do begin
    read(a[i]);
    t[i]:=i;
  end;
  qsort(1,n);
  writeln((n+1) div 2);
  for i:=1 to (n+1)div 2 do
    write(t[2*i-1],' ');
  writeln;
  writeln(n div 2);
  for i:=1 to n div 2 do
    write(t[2*i],' ');
end.