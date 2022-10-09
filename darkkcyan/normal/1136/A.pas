uses math;
const maxn = 101010;

var
    n: longint;
    pend: array[0..maxn] of longint;
    k: longint;
    i: longint;
    ans: longint;

begin
    read(n);
    for i := 1 to n do begin
        read(pend[i], pend[i]);
    end;
    
    read(k);
    ans := 0;
    for i := 1 to n do begin
        inc(ans, byte(pend[i] >= k));
    end;
    writeln(ans);
end.