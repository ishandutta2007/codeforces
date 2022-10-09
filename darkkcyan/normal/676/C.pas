uses math;
var
    n, k: longint;
    s: ansistring;
    cur: char;
    cnt_cur: longint;
    ans: longint;
    l, r: longint;

begin
    readln(n, k);
    readln(s);
    ans := 0;
    for cur := 'a' to 'b' do begin
        r := 1;
        cnt_cur := 0;
        for l := 1 to n do begin
            while (r <= n) do begin
                if cnt_cur + byte(s[r] = cur) > k then break;
                inc(cnt_cur, byte(s[r] = cur));
                inc(r);
            end;
            ans := max(ans, r - l);
            // writeln(cur, ' ', l, ' ', r, ' ', r - l, ' ', cnt_cur);
            dec(cnt_cur, byte(s[l] = cur));
        end;
    end;
    writeln(ans);
end.