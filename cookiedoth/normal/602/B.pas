program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
value:array[0..100001] of Integer;
ud:array[0..100001] of Boolean;
tv,n,v,udk,i:Integer;
thisvalue,maxvalue:Integer;
begin
  for i:=0 to 100001 do
  begin
    value[i]:=0;
    ud[i]:=false;
  end;
  Readln(n);
  read(v);
  tv:=v;
  udk:=1;
  value[1]:=1;
  for i:=2 to n do
  begin
    read(v);
    if (v=tv) then Inc(value[udk]);
    if (v>tv) then
    begin
      Inc(udk);
      value[udk]:=1;
      ud[udk]:=True;
      tv:=v;
    end;
    if (v<tv) then
    begin
      Inc(udk);
      value[udk]:=1;
      ud[udk]:=False;
      tv:=v;
    end;
  end;
  maxvalue:=0;
  thisvalue:=0;
  ud[1]:=not(ud[2]);
  ud[0]:=ud[2];
  for i:=1 to udk do
  begin
    if ud[i]<>ud[i-1] then
    begin
      Inc(thisvalue,value[i]);
    end;
    if ud[i]=ud[i-1] then
    begin
      if thisvalue>maxvalue then maxvalue:=thisvalue;
      thisvalue:=value[i]+value[i-1];
    end;
  end;
  if thisvalue>maxvalue then maxvalue:=thisvalue;
  Writeln(maxvalue);
end.