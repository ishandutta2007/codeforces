program project1;

{$apptype console}

uses Math, SysUtils;
var a: array[1..100]of int64;
    i,ans: int64;
    n: integer;

begin
  read(n);
  i:=1;
  while (i<=n)do begin
    read(a[i]);
    inc(i);
  end;
  ans:=0;
  i:=1;
  while (i<=n)do begin
    ans:=ans+(a[i]-1)*(i-1)+a[i];
    inc(i);
  end;
  write(ans);
end.