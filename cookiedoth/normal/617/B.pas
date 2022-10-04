var
    n,i,m,x:Integer;
    ans:Int64;
begin
    Readln(N);
    m:=-1;
    ans:=0;
    for i:=1 to n do
    begin
        Read(X);
        if x=0 then if m>=0 then inc(m);
        if x=1 then
        begin
            if m=-1 then begin m:=1; ans:=1; end
            else
            begin
                ans:=ans*m;
                m:=1;
            end;
        end;
    end;
    write(ans);
end.