program task_3;

{$APPTYPE CONSOLE}
uses
  Math,
  SysUtils;
const md = round(1e9)+ 7;
var n,m,i,j: integer;
    ans:int64;
    c:char;
    s: array[1..100]of string;
    a: array[1..100]of integer;
    used: array[1..100,'A'..'Z']of boolean;

begin
  readln(n,m);
  for i:=1 to m do begin
    for c:='A' to 'Z'do
      used[i,c]:=false;
    a[i]:=0;
  end;
  for i:=1 to n do readln(s[i]);
  for i:=1 to n do
    for j:=1 to m do
      if (not used[j,s[i][j]])then begin
        inc(a[j]);
        used[j,s[i][j]]:=true;
      end;
  ans:=1;
  for i:=1 to m do ans:=(ans*a[i])mod md;
  write(ans);
end.