var st:string;a,b,i:longint;
begin
readln(b);
readln(st);
for i:=1 to length(st) do
begin
if ord(st[i])=48+8 then inc(a);
end;
if (b div 11)<a then a:=b div 11;
writeln(a);
end.