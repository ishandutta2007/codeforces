program task_1;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var s1,s2: string;
    n1,n2,i,ans: integer;

function check(v: integer): boolean;
var g,t: string;
    k1,k2,i: integer;
begin
  t:=copy(s1,1,v);
  k1:=n1 div v;
  k2:=n2 div v;
  for i:=1 to k1-1 do begin
    g:=copy(s1,i*v+1,v);
    if (g<>t)then begin
      check:=false;
      exit;
    end;
  end;
  for i:=0 to k2-1 do begin
    g:=copy(s2,i*v+1,v);
    if (g<>t)then begin
      check:=false;
      exit;
    end;
  end;
  check:=true;
end;

begin
  readln(s1);
  readln(s2);
  n1:=length(s1);
  n2:=length(s2);
  ans:=0;
  for i:=1 to min(n1,n2)do
    if (n1 mod i=0)and(n2 mod i=0)and(check(i))then
      inc(ans);
  write(ans);
end.