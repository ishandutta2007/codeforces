uses math;
const max_char = 26;
const max_2_char = max_char * max_char;

var
    cnt: array [0..max_2_char] of longint;

function two_gram_to_int(const s: string): longint;
begin
    result := (ord(s[1]) - ord('A')) * max_char + ord(s[2]) - ord('A');
end;

function int_to_two_gram(x: longint): string;
begin
    result := char(x div max_char + ord('A')) + char(x mod max_char + ord('A'));
end;

var n: longint;
var s: string;
var i: longint;
var ans: longint;

begin
    readln(n);
    readln(s);
    fillchar(cnt, sizeof(cnt), 0);
    for i := 1 to n - 1 do 
        inc(cnt[two_gram_to_int(s[i] + s[i + 1])]);
        
    ans := 0;
    for i := 1 to max_2_char do 
        if (cnt[i] > cnt[ans]) then ans := i;
    
    writeln(int_to_two_gram(ans));
    
end.