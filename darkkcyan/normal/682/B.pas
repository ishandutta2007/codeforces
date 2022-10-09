uses math;
const maxn = 1000 * 1000;

var 
    n: longint;
    cnt: array[0..maxn] of longint;
    i: longint;
    a: longint;
    ans : longint;
    
begin
    read(n);
    for i := 1 to n do begin
        read(a);
        if a > maxn then a := maxn;
        inc(cnt[a]);
    end;
    ans := 0;
    
    i := 0;
    
    for ans := 1 to n + 1 do begin
        i := max(i, ans);
        while (i <= maxn) and (cnt[i] = 0) do inc(i);
        if i > maxn then break;
        dec(cnt[i]);
    end;
    writeln(ans);
end.