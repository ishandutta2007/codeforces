uses math;
const maxn = 201010;

var
    ntest: longint;
    n, k: longint;
    a: array[0..maxn] of longint;
    cnt: array[0..maxn] of longint;
    cur_col: array[0..maxn] of longint;
    acc_col: array[0..maxn] of longint;
    i, f: longint;
    cnt_small: longint;

begin
    fillchar(cnt, sizeof(cnt), 0);
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, k);
        for i := 1 to n do read(a[i]);
        for i := 1 to n do inc(cnt[a[i]]);
        
        cnt_small := 0;
        for i := 1 to n do begin
            if cnt[i] >= k then cur_col[i] := k
            else begin
                cur_col[i] := 0;
                inc(cnt_small, cnt[i]);
                acc_col[i] := cnt[i];
            end;
        end;
        i := n;
        for f := 1 to cnt_small mod k do begin
            while (i > 0) and (acc_col[i] = 0) do dec(i);
            dec(acc_col[i]);
        end;
        for i := 1 to n do begin
            inc(acc_col[i], acc_col[i - 1]);
            if cnt[i] < k then cur_col[i] := acc_col[i];
        end;
        
        cnt_small := cnt_small - cnt_small mod k;
        
        for i := 1 to n do begin
            if (cnt[a[i]] >= k) then begin
                write(cur_col[a[i]], ' ');
                if cur_col[a[i]] > 0 then
                    dec(cur_col[a[i]]);
            end else if (cur_col[a[i]] > acc_col[a[i] - 1]) then begin
                dec(cur_col[a[i]]);
                write(cur_col[a[i]] mod k + 1, ' ');
            end else write('0 ');
        end;
        writeln;
        
        for i := 1 to n do begin
            cnt[a[i]] := 0;
            acc_col[i] := 0;
            cur_col[i] := 0;
        end;
    end;
end.