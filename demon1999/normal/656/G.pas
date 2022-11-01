var f,i,t,a,j,q,p,kitten:integer;
    s:array[1..20]of string;
begin
    readln(f,i,t);
    for j:=1 to f do
    readln(s[j]);
    for j:=1 to i do begin
    p:=0;
    for q:=1 to f do
    if s[q,j]='Y'then p+=1;
    if p>=t then a+=1;
    end;
    write(a);
end.