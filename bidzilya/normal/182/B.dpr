program task_1;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var n,ans,a,i,d: integer;
begin
  read(d,n);
  ans:=0;
  for i:=1 to n-1 do begin
    read(a);
    ans:=ans+d-a;
  end;
  write(ans);
end.