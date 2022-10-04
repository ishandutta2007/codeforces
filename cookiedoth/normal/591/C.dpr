program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,x,max,k,j:Integer;
  m:array[1..500000] of Boolean;
  s:array[1..500000] of Boolean;
begin
  Readln(n);
  for i:=1 to n do
  begin
    read(x);
    if x=0 then m[i]:=False
    else m[i]:=true;
  end;
  s[1]:=true;
  s[n]:=true;
  for i:=2 to n-1 do
  begin
    if (m[i]<>m[i-1]) and (m[i]<>m[i+1]) then
      s[i]:=false
    else
      s[i]:=True;
  end;
  max:=0;
  k:=0;
  for i:=2 to n do
  begin
    if s[i]=False then
    begin
      inc(k);
    end;
    if (s[i]=True) and (s[i-1]=False) then
    begin
      if ((k-1) div 2)+1>max then max:=((k-1) div 2)+1;
      if (k mod 2)=1 then
      begin
        for j:=1 to k do
          m[i-j]:=m[i];
      end;
      if (k mod 2)=0 then
      begin
        for j:=1 to (k div 2) do
          m[i-j]:=m[i];
        for j:=(k div 2)+1 to k do
          m[i-j]:=m[i-k-1];
      end;
      k:=0;
    end;
  end;
  Writeln(max);
  for i:=1 to n do
  begin
    if m[i]=true then Write('1 ')
    else Write('0 ');
  end;
//  Readln(n);
end.