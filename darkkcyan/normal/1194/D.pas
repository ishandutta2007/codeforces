uses math;

const player: array [false..true] of string = ('Alice', 'Bob');

function cal(n, k: longint): boolean;
begin
    if (n + 1 < k) or (k mod 3 <> 0) then exit(n mod 3 = 0);
    n := n mod (k + 1);
    result := (n <> k) and (n mod 3 = 0);
end;

var
    ntest, testcase: longint;
    n, k: longint;
begin
    read(ntest);
    for testcase := 1 to ntest do begin
        read(n, k);
        writeln(player[cal(n, k)]);
    end;
end.