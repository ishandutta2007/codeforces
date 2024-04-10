uses math;
const maxn = 101010;
const bs = 333;

var
    n: longint;
    a: array[0..maxn] of longint;
    p: longint;
    k: longint;
    q: longint;
    i: longint;
    small_ans: array[0..bs, 0..maxn] of longint;
    
function solve_big(p, k: longint): longint;
var ans: longint;
begin
    ans := 0;
    while p <= n do begin
        inc(ans);
        inc(p, k + a[p]);
    end;
    exit(ans);
end;
    
    
begin
    read(n);
    for i := 1 to n do read(a[i]);
    fillchar(small_ans, sizeof(small_ans), 0);
    for k := 1 to bs do begin
        for i := n downto 1 do begin
            p := i + a[i] + k;
            if p > n then small_ans[k][i] := 1
            else small_ans[k][i] := small_ans[k][p] + 1;
        end;
    end;
    
    read(q);
    while q > 0 do begin
        dec(q);
        read(p, k);
        if k > bs then writeln(solve_big(p, k))
        else writeln(small_ans[k][p]);
    end;
end.