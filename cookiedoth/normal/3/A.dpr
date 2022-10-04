program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s1,s2:string;
  x1,y1,x2,y2:Integer;
  x,y:Integer;
  vxyx,vxyy,vxyk:Integer;
  vx,vy,vik:Integer;
  sw1,sw2:string;
  i:Integer;
begin
  Readln(s1);
  Readln(s2);
  x1:=ord(s1[1])-96;
  y1:=StrToInt(s1[2]);
  x2:=ord(s2[1])-96;
  y2:=StrToInt(s2[2]);
  x:=x2-x1;
  y:=y2-y1;
  if Abs(x)<Abs(y) then
  begin
    VXYK:=Abs(x);
    vik:=Abs(y)-abs(x);
    vx:=0;
    if y<>0 then
      vy:=(y div (Abs(y)))
    else
      vy:=0;
  end
  else
  begin
    vxyk:=Abs(y);
    vik:=Abs(x)-abs(y);
    if x<>0 then
      vx:=(x div (Abs(x)))
    else
      vx:=0;
    vy:=0;
  end;
  if x<>0 then
    vxyx:=(x div (Abs(x)))
  else
    vxyx:=0;
  if y<>0 then
    vxyy:=(y div (Abs(y)))
  else
    vxyy:=0;
  if (vxyx=1) and (vxyy=1) then sw1:='RU';
  if (vxyx=1) and (vxyy=-1) then sw1:='RD';
  if (vxyx=-1) and (vxyy=1) then sw1:='LU';
  if (vxyx=-1) and (vxyy=-1) then sw1:='LD';
  if (vx=1) then sw2:='R';
  if (vx=-1) then sw2:='L';
  if (vy=1) then sw2:='U';
  if (vy=-1) then sw2:='D';
  Writeln(vxyk+vik);
  for i:=1 to vxyk do
    Writeln(sw1);
  for i:=1 to vik do
    Writeln(sw2);
  Readln(s1);
end.