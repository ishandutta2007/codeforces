program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
s: string;
 r, p, l, e: int64;
begin
  readln(s);
 // val(copy(s, 1, length(s)-1), r, e);
  r:= StrToInt64(copy(s, 1, length(s)-1));
  l := length(s);
  case s[l] of
    'f': p := 1;
    'e': p:=2;
    'd': p:=3;
    'a': p:=4;
    'b': p:=5;
    'c': p:=6;
  end;
  r := r - 1;
  if ((r mod 4) = 0) then
  begin
    writeln(r + (r * 3) + p);
  end;
  if ((r mod 4) = 1) then
  begin
    writeln(r + 6 + ((r-1) * 3) + p);
  end;
  if ((r mod 4) = 2) then
  begin
    r:= r - 2;
    writeln(r + (r * 3) + p);
    r:=r+2;
  end;
  if ((r mod 4) = 3) then
  begin
    r:= r -2;
    writeln(r + 6 + ((r-1) * 3) + p);
    r:= r+2;
  end;
end.