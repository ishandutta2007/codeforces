var
    prime:array[1..2000000] of boolean;
    p:array[1..2000000] of integer;
    m:array[1..1000] of integer;
    i,j,f,n,one,x1,x2,a,b,c:integer;
    pr:boolean;
begin
    for i:=1 to 2000000 do
    begin
        prime[i]:=false;
        p[i]:=0;
    end;
    p[1]:=2;
    prime[2]:=true;
    f:=1;
    for i:=3 to 2000000 do
    begin
        pr:=true;
        for j:=1 to f do
        begin
            if p[j]*p[j]>i then break;
            if (i mod p[j])=0 then
            begin
                pr:=false;
                break;
            end;
        end;
        if pr then
        begin  
            inc(f);
            p[f]:=i;
            prime[i]:=true;
        end;
    end;
    readln(n);
    one:=0;
    for i:=1 to n do 
    begin
        read(m[i]);
        if m[i]=1 then inc(one);
    end;
    a:=0;
    b:=0;
    c:=0;
    for i:=1 to n do
    begin
        for j:=1 to n do
        begin   
            if (prime[m[i]+m[j]]) and (i<>j) then
            begin  
                a:=i;
                b:=j;
            end;
        end;
    end;
    if (a>0) then x1:=2
    else
    begin
        a:=1;
        x1:=1;
    end;
    x2:=one;
    for i:=1 to n do
    begin
        if (prime[m[i]+1]) and (m[i]>1) then
        begin
            c:=i;
            x2:=one+1;
            break;
        end;
    end;
    if x1>x2 then
    begin
        writeln(x1);
        if x1=1 then write(m[1])
        else write(m[a],' ',m[b]);
    end
    else
    begin
        writeln(x2);
        for i:=1 to one do 
            write('1 ');
        if x2>one then write(m[c]);
    end;
end.