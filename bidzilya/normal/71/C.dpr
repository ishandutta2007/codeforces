program project1;

{$apptype console}

uses Math, SysUtils;
var n,i,j: integer;
    a: array[1..100000]of integer;

function check(s,h: integer): boolean;
var t: integer;
begin
  t:=s;
  repeat
    if (a[t]=0)then begin
      check:=false;
      exit;
    end;
    t:=t+h;
    if (t>n)then
      t:=t-n;
  until (t=s);
  check:=true;
end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=3 to n do
    if (n mod i=0)then
      for j:=1 to n div i do
        if (check(j,n div i))then begin
          writeln('YES');
          halt;
        end;
  writeln('NO');
end.