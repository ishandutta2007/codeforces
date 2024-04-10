program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var i,j,buf,sum,tsum,ans,n: integer;
    a: array[1..100]of integer;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      if (a[j]<a[i])then begin
        buf:=a[i];a[i]:=a[j];a[j]:=buf;
      end;
  sum:=0;
  for i:=1 to n do
    sum:=sum+a[i];
  tsum:=0;
  ans:=0;
  while (tsum<=sum)do begin
    inc(ans);
    tsum:=tsum+a[n-ans+1];
    sum:=sum-a[n-ans+1];
  end;
  write(ans);
end.