uses math;
const maxn = 201010;

var
    cnt_a: array[0..maxn] of int64;
    sum_pos: array[0..maxn] of int64;
    cnt_pos: array[0..maxn] of longint;
    n, q: longint;
    temp, ans: int64;
    i: longint;
    l, r: longint;

begin
    fillchar(cnt_a, sizeof(cnt_a), 0);
    readln(n, q);
    for i := 1 to n do begin
        read(temp);
        inc(cnt_a[temp]);
    end;
    
    fillchar(sum_pos, sizeof(sum_pos), 0);
    for i := 1 to q do begin
        read(l, r);
        inc(sum_pos[l]);
        dec(sum_pos[r + 1]);
    end;
    
    fillchar(cnt_pos, 0, sizeof(cnt_pos));
    for i := 1 to maxn do begin
        inc(sum_pos[i], sum_pos[i - 1]);
        inc(cnt_pos[sum_pos[i]]);
    end;
    
    l := maxn; r := maxn;
    while true do begin
        while (l >= 0) and (cnt_a[l] = 0) do dec(l);
        while (r >= 0) and (cnt_pos[r] = 0) do dec(r);
        if (l = 0) or (r = 0) then break;
        temp := min(cnt_a[l], cnt_pos[r]);
        dec(cnt_a[l], temp);
        dec(cnt_pos[r], temp);
        inc(ans, temp * l * r);
    end;
    writeln(ans);
end.