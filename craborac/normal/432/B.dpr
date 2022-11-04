
{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, i, k:integer;
    a, b, mas:array[1..100000] of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  for i := 1 to 100000 do
    mas[i] := 0;
  readln(n);
  for i := 1 to n do
  begin
    readln(a[i], b[i]);
    mas[a[i]] := mas[a[i]] + 1;
  end;
  for i := 1 to n do
  begin
    k := n - 1 + mas[b[i]];
    writeln(k,' ',2 * n - 2 - k);
  end;
  readln;
  readln;
end.