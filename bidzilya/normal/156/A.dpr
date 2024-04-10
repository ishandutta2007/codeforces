program task_1;

{$APPTYPE CONSOLE}

uses SysUtils, Math;
var s,u,tmp: string;
    p,i,j,ans: integer;
begin
  readln(s);
  readln(u);
  ans:=maxint;
  tmp:='';
  for i:=1 to 2100 do
    tmp:=tmp+'#';
  s:=tmp+s+tmp;
  for i:=1 to length(s)-length(u)+1 do begin
    p:=0;
    for j:=1 to length(u)do begin
      if (s[i+j-1]<>u[j])then inc(p);
      ans:=min(ans,p+length(u)-j);
    end;
  end;
  writeln(ans);
end.