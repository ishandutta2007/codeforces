program TaskC;
var
mnum,mup:array[1..200000] of Int64;
n,knum,summ,a,x,k,t:Int64;
i:Integer;
begin
    Readln(n);
    for i:=1 to 200000 do
    begin
        mup[i]:=0;
        mnum[i]:=0;
    end;
    knum:=1;
    summ:=0;
    for i:=1 to n do
    begin
        Read(t);
        if t=1 then
        begin
            Read(a,x);
            if a>knum then a:=knum;
            summ:=summ+a*x;
            mup[a]:=mup[a]+x;
        end;
        if t=2 then
        begin
            Read(k);
            inc(knum);
            mnum[knum]:=k;
            inc(summ,k);
        end;
        if t=3 then
        begin
            dec(summ,mnum[knum]+mup[knum]);
            inc(mup[knum-1],mup[knum]);
            dec(knum);
            mnum[knum+1]:=0;
            mup[knum+1]:=0;
        end;
        Writeln(summ/knum);
    end;
end.