var d:array[-1..10,-1..10]of longint;
    i,j,a,b,a1,b1,n:longint;s:string;
begin
readln(s);
fillchaR(D,SIZEOF(D),0);
a:=byte(s[1])-96; a1:=a;
b:=byte(s[2])-48; d[a,b]:=1;b1:=b;
for i:=1 to 8 do begin
    d[a,i]:=1;d[i,b]:=1;
    end;
readln(s);
a:=byte(s[1])-96;
b:=byte(s[2])-48;d[a,b]:=1;
d[a+1,b+2]:=1;
d[a-1,b+2]:=1;
d[a+1,b-2]:=1;
d[a-1,b-2]:=1;
d[a+2,b+1]:=1;
d[a-2,b+1]:=1;
d[a+2,b-1]:=1;
d[a-2,b-1]:=1;
d[a1+1,b1+2]:=1;
d[a1-1,b1+2]:=1;
d[a1+1,b1-2]:=1;
d[a1-1,b1-2]:=1;
d[a1+2,b1+1]:=1;
d[a1-2,b1+1]:=1;
d[a1+2,b1-1]:=1;
d[a1-2,b1-1]:=1;

n:=0;
for i:=1 to 8 do
    for j:=1 to 8 do begin
        if (d[i,j]=0)then inc(n);end;
writeln(n);
end.