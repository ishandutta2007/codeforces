program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,a,b,ta,ans,i: integer;
begin
  read(n);
  ta:=0;
  ans:=0;
  for i:=1 to n do begin
    read(a,b);
    ta:=ta-a+b;
    if (ta>ans)then
      ans:=ta;
  end;
  write(ans);
end.