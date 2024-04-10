program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,j,x,y,m,max:Integer;
  mass:array[1..26,1..26] of Integer;
  letters:array[1..26] of Boolean;
  dif:array[1..100] of Integer;
  s:String;
begin
  Readln(n);
  for i:=1 to 26 do
    for j:=1 to 26 do
      mass[i,j]:=0;
  for i:=1 to 100 do
    dif[i]:=0;
  for i:=1 to n do
  begin
    Readln(s);
    for j:=1 to 26 do
      letters[j]:=false;
    for j:=1 to Length(s) do
    begin
      if letters[ord(s[j])-96]=False then
      begin
        letters[ord(s[j])-96]:=True;
        Inc(dif[i]);
      end;
    end;
    if dif[i]=2 then
    begin
      x:=0;
      y:=0;
      for j:=1 to 26 do
      begin
        if letters[j]=True then
        begin
          if x=0 then x:=j
          else y:=j;
        end;
      end;
      Inc(mass[x,y],Length(s));
      Inc(mass[y,x],Length(s));
    end;
    if dif[i]=1 then
    begin
      for j:=1 to 26 do
      begin
        if letters[j]=True then
        begin
          for m:=1 to 26 do
          begin
            Inc(mass[m,j],Length(s));
            Inc(mass[j,m],Length(s));
          end;
          Dec(mass[j,j],Length(s));
          Break;
        end;
      end;
    end;
  end;
  max:=0;
  for i:=1 to 26 do
    for j:=1 to 26 do
      if mass[i,j]>max then max:=mass[i,j];
  Writeln(max);
end.