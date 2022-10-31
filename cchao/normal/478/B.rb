def f(x)
    return x * (x - 1) / 2
end

a = gets.chomp.split.map(&:to_i)

n = a[0]
m = a[1]

t = n / m
tt = n % m

bb = m - tt

puts bb * f(t) + tt * f(t + 1)

puts f(n - m + 1)