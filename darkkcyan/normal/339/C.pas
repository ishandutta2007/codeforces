{$COPERATORS ON}
{$MACRO ON}
{$DEFINE proc:=procedure}
{$DEFINE func:=function}
const
maxw = 11;
maxm = 1010;
var
w: string;
m: longint;
dp: array[0..maxm, 0..maxw] of longint;

i, f, g: longint;

func printans(i, u: longint): longint;
var
last: longint;
begin
    //writeln(stderr, i, ' ', u, ' ', dp[i][u]);
    if i = 0 then exit(maxw);
    for last := 1 to maxw do
        if ((dp[i][u] shr last) and 1) = 1 then break;
    dp[i - 1][last - u] := dp[i - 1][last - u] and (not (1 shl last));
    printans(i - 1, last - u);
    write(last, ' ');
end;

begin
    readln(w); read(m);
    fillchar(dp, sizeof(dp), 0);
    for i := 1 to length(w) do 
        if w[i] = '1' then dp[1][i] := 1 shl i;
    for i := 1 to m - 1 do begin
        for f := 0 to maxw do begin
            //writeln(stderr, i, ' ', f, ' ', dp[i][f]);
            if dp[i][f] = 0 then continue;
            for g := 1 to length(w) do begin
                if w[g] = '0' then continue;
                if g <= f then continue; 
                if dp[i][f] = 1 shl g then continue;
                dp[i + 1][g - f] := dp[i + 1][g - f] or (1 shl g);
            end;
        end;
    end;
    for i := 0 to maxw do begin
        //writeln(stderr, i, ' ', dp[m][i]);
        if dp[m][i] = 0 then continue;
        writeln('YES');
        printans(m, i);
        halt;
    end;
    writeln('NO');
end.