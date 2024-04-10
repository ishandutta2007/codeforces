var
n,m,k,i,j,q,t,jj:integer;
a,b:array[1..100] of integer;
begin  
    readln(n,m,k);
    t:=0;
    for i:=1 to k do read(a[i]);
    for i:=1 to n*m do
    begin
        read(q);
        b[1]:=q;
        jj:=2;
        for j:=1 to k do
        begin
            if a[j]=q then inc(t,j)
            else begin b[jj]:=a[j]; inc(jj); end;
        end;
        a:=b;
    end;
    write(t);
end.