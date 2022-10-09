const maxn = 1010;
var
  n: longint;
  s: ansistring;
  i, f: longint;
  cnt: array['a'..'z'] of longint;
  g: char;
  ok: boolean;

begin
  readln(n);
  readln(s);
  for i := 1 to n do begin
    fillchar(cnt, sizeof(cnt), 0);
    for f := i to n do begin
      inc(cnt[s[f]]);
      ok := true;
      for g := 'a' to 'z' do
        if cnt[g] > (f - i + 1) div 2 then begin
          ok := false;
          break;
        end;
      if not ok then continue;
      writeln('YES');
      writeln(copy(s, i, f - i + 1));
      exit;
    end;
  end;
  writeln('NO');
end.