program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
var s: string;
    i,sum,ans: integer;
begin
  sum:=0;ans:=0;
  readln(s);
  for i:=1 to length(s)do
    if (s[i]>='a')and(s[i]<='z')then
      inc(sum)
    else
    if (s[i]>='A')and(s[i]<='Z')and(sum<>0)then begin
      dec(sum);
      inc(ans);
    end;
  write(ans);
end.