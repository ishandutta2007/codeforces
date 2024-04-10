program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,m,i,j:Integer;
  c1,c2:Char;
  s:string;
  let:array[1..200000] of Integer;
  fb:array[1..26] of Char;
begin
  Readln(n,m);
  Readln(s);
  for i:=1 to n do
    let[i]:=Ord(s[i])-96;
  for i:=1 to 26 do
    fb[i]:=chr(i+96);
  for i:=1 to m do
  begin
    read(c1);
    read(c2);
    read(c2);
    for j:=1 to 26 do
    begin
      if fb[j]=c1 then fb[j]:=c2
      else
      begin
        if fb[j]=c2 then fb[j]:=c1;
      end;
    end;
    Readln;
  end;
  for i:=1 to n do
    Write(fb[let[i]]);
  Readln(n);
end.