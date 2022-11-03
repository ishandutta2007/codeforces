program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,i,j,buf: integer;
    cnt,a: array[1..1000]of integer;

begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      if (a[j]<a[i])then begin
        buf:=a[i];a[i]:=a[j];a[j]:=buf;
      end;
  j:=1;
  cnt[1]:=1;
  for i:=2 to n do
    if (a[i]<>a[j])then begin
      inc(j);
      cnt[j]:=1;
      a[j]:=a[i];
    end else
      inc(cnt[j]);
  buf:=cnt[1];
  for i:=2 to j do
    if (cnt[i]>buf)then
      buf:=cnt[i];
  write(buf,' ',j);
end.