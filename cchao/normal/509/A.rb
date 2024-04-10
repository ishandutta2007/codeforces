def fac(n)
	return n == 0 ? 1 : n * fac(n - 1)
end

n = gets.to_i - 1
puts fac(n + n) / fac(n) / fac(n)