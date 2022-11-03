program Task3;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;

var n,i,m,y1,y2: integer;
    c,k,p: array[1..111]of int64;
    ans,x,tcnt,tm: int64;

procedure qsort(l,r: integer);
var i,j:integer;
    x,buf:int64;
begin
  i:=l;j:=r;x:=c[i+random(j-i+1)];
  repeat
    while (c[i]<x)do inc(i);
    while (c[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=c[i];c[i]:=c[j];c[j]:=buf;
      buf:=k[i];k[i]:=k[j];k[j]:=buf;
      inc(i);dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

begin
  randomize;
  read(n);
  for i:=1 to n do
    read(k[i],c[i]);
  qsort(1,n);
  read(m);
  for i:=1 to m do
    read(p[i]);
  inc(m);p[m]:=round(1e18);
  ans:=0;
  y1:=1;y2:=1;tm:=1;tcnt:=0;
  while (y1<=n)do
    if (tcnt+k[y1]>p[y2])then begin
      x:=p[y2]-tcnt;
      k[y1]:=k[y1]-x;
      ans:=ans+x*tm*c[y1];
      tcnt:=tcnt+x;
      inc(y2);
      inc(tm);
    end else begin
      ans:=ans+k[y1]*c[y1]*tm;
      tcnt:=tcnt+k[y1];
      inc(y1);
    end;
  writeln(ans);
end.