{$mode objfpc}
uses math;

var
    n: longint;
    s: ansistring;
    i: longint;
    has_zero: boolean;
    cnt_even: longint;
    s3: longint;
    dig: longint;

begin
    readln(n);
    while n > 0 do begin
        dec(n);
        readln(s);
        // writeln(s);
        has_zero := false;
        cnt_even := 0;
        s3 := 0;
        for i := 1 to length(s) do begin
            dig := ord(s[i]) - ord('0');
            if dig = 0 then has_zero := true;
            if dig mod 2 = 0 then inc(cnt_even);
            s3 := (s3 + ord(s[i]) - ord('0')) mod 3;
        end;
        if has_zero and (cnt_even >= 2) and (s3 = 0) then writeln('red')
        else writeln('cyan');
    end;
end.