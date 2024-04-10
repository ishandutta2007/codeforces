program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,m,i,j,a,b,ans:Integer;
begin
  Readln(n,m);
  ans:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      Read(a,b);
      if (a>0) or (b>0) then Inc(ans);
    end;
  end;
  Writeln(Ans);
end.