var n,m,k,i,o,mi1,mi2,ma,a,b:longint;
begin
readln(n,m);
read(a);
mi1:=a;
ma:=a;
for i:=2 to n do begin
    read(a);
    if a<mi1 then mi1:=a;
    if a>ma then ma:=a;
    end;
readln;
read(b);
mi2:=b;
for i:=2 to m do begin
    read(b);
    if b<mi2 then mi2:=b;
end;
mi1:=2*mi1;
if mi1<ma then mi1:=ma;
if mi1<mi2 then write(mi1)
           else write('-1');
end.