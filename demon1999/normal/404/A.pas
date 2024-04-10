var a:array[1..301,1..301]of char;
    n,i,j,k:longint;
    p,q:char;
begin
readln(n);
for i:=1 to n do begin
    for j:=1 to n do read(a[i,j]);
    readln;
    end;
p:=a[1,1];
q:=a[2,1];
if p=q then begin writeln('NO'); halt;end;
for i:=1 to n do
    for j:=1 to n do begin
        if ((i=j)or(i=n-j+1))and(a[i,j]<>p)then begin writeln('NO');halt;
        end;
        if ((i<>j)and(i<>n-j+1)and(a[i,j]<>q))then begin writeln('NO');halt;end;
        end;
writeln('YES');
end.