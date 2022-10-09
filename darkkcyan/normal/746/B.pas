const maxn = 2222;
var
    n: integer;
    s, res: ansistring;
    i, cur_len, f, cnt: integer;

begin
    readln(n);
    readln(s);
    res := '';
    for i := 1 to n do res := res + ' ';
    for i := 1 to n do begin
        cur_len := n - i + 1;
        cnt := 0;
        for f := 1 to n do begin
            if res[f] <> ' ' then continue;
            inc(cnt);
            if cnt = (cur_len + 1) div 2 then break;
        end;
        res[f] := s[i];
    end;

    write(res);
end.