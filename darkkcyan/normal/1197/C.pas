{$mode objfpc}
uses classes, fgl;
const maxn = 301010;
type
    LongIntList = specialize TFPGList<longint>;

function cmp_longint(const u, v: longint): integer;
begin
    if u > v then result := 1
    else if u < v then result := -1
    else result := 0;
end;

var
    n, k: longint;
    a: array [0..maxn] of longint;
    diff: LongIntList;
    i: longint;
    ans: longint;

begin
    read(n, k);
    for i := 1 to n do read(a[i]);
    diff := LongIntList.create();
    for i := 1 to n - 1 do 
        diff.add(a[i + 1] - a[i]);
    
    diff.sort(@cmp_longint);
    ans := a[n] - a[1];
    for i := n - 1 downto n - k + 1 do
        dec(ans, diff[i - 1]);
    writeln(ans);
    diff.free;
end.