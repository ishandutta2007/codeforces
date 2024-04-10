{$mode objfpc}
uses math;

var 
    ntest, testcase: longint;
    n, i: longint;
    a, temp: longint;
    max_1, max_2: longint;

begin
    read(ntest);
    for testcase := 1 to ntest do begin
        read(n);
        max_1 := 0; max_2 := 0;
        for i := 1 to n do begin
            read(a);
            if a > max_1 then begin
                temp := a;
                a := max_1;
                max_1 := temp;
            end;    
            if a > max_2 then begin
                temp := a;
                a := max_2;
                max_2 := temp;
            end;
        end;

        writeln(min(max_2 - 1, n - 2));
    end;
end.