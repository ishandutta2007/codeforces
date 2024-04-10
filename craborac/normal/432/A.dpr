
{$APPTYPE CONSOLE}

uses
  SysUtils;
var i, n, k, col, a:integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  readln(n, k);
  col := 0;
  for i := 1 to n do
  begin
    read(a);
    if(a <= 5 - k) then
      col := col + 1;
  end;
  writeln(col div 3);
  readln;
  readln;
end.