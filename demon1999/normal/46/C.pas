var s,s1:string;
    k,j,i,min,n:longint;
begin
readln(n);
readln(s);
s1:='';
for i:=1 to n do
    if s[i]='H' then s1:='H'+s1
                else s1:=s1+'T';
min:=1001;
for i:=1 to n do begin
    k:=0;
    for j:=1 to n do
        if s[j]<>s1[j] then inc(k);
    k:=k div 2;
    if k<min then min:=k;
    s1:=s1[n]+s1;
    delete(s1,n+1,1);
    end;
writeln(min);
end.