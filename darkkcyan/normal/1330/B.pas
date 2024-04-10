uses math;

const maxn = 201010;

var
    ntest: longint;
    n: longint;
    a: array[0..maxn] of longint;
    has: array[0..maxn] of boolean;
    i: longint;
    cur_has: longint;
    
    ans: longint;
    u, v: array[0..maxn] of longint;
    ok_beg, ok_end: array[0..maxn] of boolean;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        for i := 1 to n do has[i] := false;
        for i := 1 to n do begin
            ok_beg[i] := false;
            ok_end[i] := false;
        end;
        
        cur_has := 0;
        ans := 0;
        for i := 1 to n do begin
            has[a[i]] := true;
            while has[cur_has + 1] do inc(cur_has);
            if cur_has = i then ok_beg[i] := true;
        end;
        
        for i := 1 to n do has[i] := false;
        cur_has := 0;
        for i := n downto 1 do begin
            has[a[i]] := true;
            while has[cur_has + 1] do inc(cur_has);
            if cur_has = n - i + 1 then ok_end[cur_has] := true;
        end;
        
        for i := 1 to n do begin
            if not ok_beg[i] then continue;
            if not ok_end[n - i] then continue;
            inc(ans);
            u[ans] := i;
            v[ans] := n - i;
        end;
        writeln(ans);
        for i := 1 to ans do writeln(u[i], ' ', v[i]);
    end;
end.