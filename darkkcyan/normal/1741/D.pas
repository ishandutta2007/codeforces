uses math;
const maxn = 3010100;

var
    n: longint;
    a: array [0..maxn] of longint;
    
type solve_res = record
    min_val: longint;
    max_val: longint;
    ans: longint;
end;

function solve(l, r: longint): solve_res;
var
    cur, left_ans, right_ans: solve_res;
    mid: longint;
begin
    if r - l = 1 then begin
        cur.min_val := a[l];
        cur.max_val := a[l];
        cur.ans := 0;
        exit(cur);
    end;
    
    mid := (l + r) div 2;
    left_ans := solve(l, mid);
    right_ans := solve(mid, r);
    cur.ans := -1;
    if (left_ans.ans = -1) or (right_ans.ans = -1) then begin
        exit(cur);
    end;
    if min(left_ans.max_val, right_ans.max_val) + 1 <> max(left_ans.min_val, right_ans.min_val) then begin
        exit(cur);
    end;
    cur.min_val := min(left_ans.min_val, right_ans.min_val);
    cur.max_val := max(left_ans.max_val, right_ans.max_val);
    cur.ans := left_ans.ans + right_ans.ans;
    if left_ans.min_val = right_ans.max_val + 1 then inc(cur.ans);
    exit(cur);
end;

var ntest: longint;
var i: longint;
begin
    read(ntest);
    while (ntest > 0) do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        writeln(solve(1, n + 1).ans);
    end;
end.