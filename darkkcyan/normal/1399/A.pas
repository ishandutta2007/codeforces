uses math;

var n: integer;
var test: integer;
var i: integer;
var cnt: array[0..111] of integer;
var num: integer;
var mi, ma: integer;
var ans: boolean;

begin
    read(test);
    while test > 0 do begin
        dec(test);
        read(n);
        fillchar(cnt, sizeof(cnt), 0);
        mi := 111;
        ma := 0;
        for i := 1 to n do begin
            read(num);
            inc(cnt[num]);
            mi := min(mi, num);
            ma := max(ma, num);
        end;
        
        ans := true;
        for i := mi to ma do begin
            if cnt[i] > 0 then continue;
            ans := false;
            break;
        end;
        if ans then writeln('YES')
        else writeln('NO');
    end;
end.