var
	n : longint;
	A : array [1 .. 70] of longint;
	dp : array [0 .. 70, 0 .. 30, 0 .. 2500] of boolean;
	B : array [1 .. 70] of longint;
	mat : array [1 .. 70, 1 .. 70] of longint;

procedure swap(var i, j : longint);
var t : longint;
begin t := i; i := j; j := t; end;

function calc(x : longint) : longint;
begin calc := x * (x - 1) div 2; end;

var i, j, k : longint;
var ai, aj, ak : longint;
var m : longint;
begin
	readln(n);
	for i := 1 to n do read(A[i]);
	for i := 1 to n do
		for j := i + 1 to n do
			if A[i] > A[j] then
				swap(A[i], A[j]);
	dp[0, 0, 0] := true;
	for i := 0 to 70 do begin
		for j := 0 to n do
			for k := calc(i) to 2500 do
				if dp[i, j, k] then begin
					if k + A[j + 1] <= 2500 then
						dp[i + 1, j + 1, k + A[j + 1]] := true;
					if (j > 0) and (k + A[j] <= 2500) then
						dp[i + 1, j, k + A[j]] := true;
				end;
		if (i > 0) and dp[i, n, calc(i)] then begin
			ai := i; aj := n; ak := calc(i);
			break;
		end;
		if ai > 0 then break;
	end;
	if ai = 0 then begin
		writeln('=(');
		halt;
	end;
	m := 0;
	while ai <> 0 do begin
		if not dp[ai, aj, ak] then dec(aj);
		inc(m);
		B[m] := A[aj];
		dec(ai); dec(ak, A[aj]);
	end;
	for i := m div 2 downto 1 do swap(B[i], B[m - i + 1]);
	for i := 1 to m do A[i] := i;
	writeln(m);
	for i := m downto 1 do begin
		for j := 1 to m do
			for k := j + 1 to m do
				if B[A[j]] > B[A[k]] then
					swap(A[j], A[k]);
		for j := 1 to B[A[i]] do
			mat[A[i], A[j]] := 1;
		for j := B[A[i]] + 1 to i - 1 do begin
			mat[A[j], A[i]] := 1;
			dec(B[A[j]]);
		end;
	end;
	for i := 1 to m do begin
		for j := 1 to m do
			write(mat[i, j]);
		writeln;
	end;
end.