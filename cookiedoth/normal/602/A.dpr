program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  m,n:Integer;
  bx,by,i,r:Integer;
  X,Y:Int64;
function Step(osn,pok:Integer):Int64;
var
  ii:Integer;
begin
  Result:=1;
  for ii:=1 to pok do
    result:=result*osn;
end;
begin
  Readln(n,bx);
  X:=0; Y:=0;
  for i:=n-1 downto 0 do
  begin
    read(r);
    Inc(X,r*Step(bx,i));
  end;
  Readln(m,By);
  for i:=m-1 downto 0 do
  begin
    read(r);
    Inc(Y,r*step(by,i));
  end;
  if X>Y then Write('>');
  if X=Y then Write('=');
  if X<Y then Write('<');
end.