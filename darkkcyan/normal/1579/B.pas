uses math;

const maxn = 55;

type ans_t = record
    l, r, d: longint;
end;

var
    ntest: longint;
    a: array[0..maxn] of longint;
    n: longint;
    ans_cnt: longint;
    ans: array[0..maxn] of ans_t;
    
procedure do_op1(l, r: longint);
var 
    i: longint;
    tmp: longint;
begin
    if l = r then exit();
    inc(ans_cnt);
    ans[ans_cnt].l := l;
    ans[ans_cnt].r := r;
    ans[ans_cnt].d := 1;
    tmp := a[l];
    for i := l to r - 1 do begin
        a[i] := a[i + 1];
    end;
    a[r] := tmp;
end;
    
var
    i, f, mx: longint;
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        ans_cnt := 0;
        for i := n downto 2 do begin
            mx := 1;
            for f := 2 to i do begin
                if a[f] > a[mx] then mx := f;
            end;
            do_op1(mx, i);
        end;
        writeln(ans_cnt);
        for i := 1 to ans_cnt do begin
            writeln(ans[i].l, ' ', ans[i].r, ' ', ans[i].d);
        end;
    end;
end.