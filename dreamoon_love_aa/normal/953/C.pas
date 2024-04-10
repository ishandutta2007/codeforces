var a:array [1..100000] of longint;
    i,j,n,res,fail: longint;
begin
    readln(n);
    res:=0;
    for i:=1 to n do read(a[i]);
    for i:=1 to n do 
    begin
        if (n mod i = 0) then
        begin
            fail:=0;
            for j:= 2 to n do
            begin
                if ((((j-1) mod i) = 0) and (a[j] = a[j-1])) then
                begin
                    fail := 1;
                    break;
                end;
                if ((((j-1) mod i) <> 0) and (a[j] <> a[j-1])) then
                begin
                    fail := 1;
                    break;
                end;
            end;
            if (fail = 0) then res:=1;
        end;
    end;
    if (res = 1) then writeln('YES') else writeln('NO');
end.