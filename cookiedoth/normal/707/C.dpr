program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  nn,mult,n,k:int64;
begin
  Readln(nn);
  n:=nn;
  mult:=1;
  while ((n mod 2) = 0) do
  begin
    n := n div 2;
    mult := mult * 2;
  end;
  if (n=1) then
  begin
    if (nn=1) or (nn=2) then
    begin
      Writeln(-1);
      Halt(0);
    end
    else
    begin
      mult := mult div 4;
      Writeln(3*mult,' ',5*mult);
      Halt(0);
    end;
  end;
  k:=(n*n-1) div 2;
  Writeln(k*mult,' ',(k+1)*mult);
end.