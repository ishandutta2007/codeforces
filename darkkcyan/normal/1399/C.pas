uses math;

var ntest: longint;
var n: integer;
var cnt: array[0..100] of integer;
var ans, cur_ans: longint;
var i, f, g: longint;
var num: longint;

begin
    read(ntest);
    for ntest := 1 to ntest do begin
        // writeln(stderr); 
        read(n);
        fillchar(cnt, sizeof(cnt), 0);
        for i := 1 to n do begin
            read(num);
            inc(cnt[num]);
        end;
        
        ans := 0;
        for i := 1 to 2 * n do begin
            cur_ans := 0;
            for f := 1 to n do begin
                g := i - f;
                if g < f then break;
                if f <> g then inc(cur_ans, min(cnt[f], cnt[g]))
                else inc(cur_ans, cnt[f] div 2);
            end;
            ans := max(ans, cur_ans);
            // writeln(stderr, i, ' ', cur_ans, ' ', cnt[6]); 
        end;
        writeln(ans);
    end;
end.