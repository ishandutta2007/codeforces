uses math;

const maxn = 201010;

var
    ntest: longint;
    n: longint;
    a: array [0..maxn] of longint;
    dp: array[0..maxn] of boolean;
    i: longint;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        
        for i := 0 to n do dp[i] := false;
        
        dp[0] := true;
        for i := 1 to n do begin
            if (i + a[i] <= n) and (dp[i - 1]) then dp[i + a[i]] := true;
            if (i - a[i] - 1 >= 0) and (dp[i - a[i] - 1 ]) then dp[i] := true;
        end;
        if dp[n] then writeln('YES')
        else writeln('NO');
    end;
end.