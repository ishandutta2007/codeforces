uses math;
const maxn = 201010;
type trap = record 
    l, r, d: longint;
end;

var
   m, n, k, t: longint; 
   a: array[0..maxn] of longint;
   cnt_a: array[0..maxn] of longint;
   traps: array[0..maxn] of trap;

var
    cannot_step_in: array[0..maxn] of longint;
function ok(n_soldier: longint): boolean;
var
    i, min_a: longint;
    cnt_danger: longint;
begin
    for min_a:= maxn downto 1 do begin
        dec(n_soldier, cnt_a[min_a]);
        if n_soldier <= 0 then break;
    end;

    for i := 1 to n do cannot_step_in[i] := 0;

    for i := 1 to k do begin
        if traps[i].d <= min_a then continue;
        inc(cannot_step_in[traps[i].l]);
        dec(cannot_step_in[traps[i].r + 1]);
    end;
    cnt_danger := 0;
    for i := 1 to n + 10 do begin
        inc(cannot_step_in[i], cannot_step_in[i - 1]);
        if cannot_step_in[i] > 0 then inc(cnt_danger);
    end;
    exit(cnt_danger <= t);
end;

var
    l, r, mid: longint;
    i: longint;
begin
    read(m, n, k, t);
    dec(t, n + 1);
    t := t div 2;
    fillchar(cnt_a, sizeof(cnt_a), 0);
    for i := 1 to m do begin
        read(a[i]);
        inc(cnt_a[a[i]]);
    end;

    for i := 1 to k do 
        read(traps[i].l, traps[i].r, traps[i].d);

    l := 0;
    r := m;
    while r > l do begin
        mid := (l + r + 1) div 2;
        if ok(mid) then l := mid
        else r := mid - 1;
    end;
    writeln(l);

end.