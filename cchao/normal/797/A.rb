require 'prime'

n, k = gets.chomp.split.map(&:to_i)
a = n.prime_division
sum = (a.map do | x | x[1] end).inject(0, :+)

if sum < k
  puts -1
else
  for x in a
    for i in 1..x[1]
      if k == 1
        break
      end
      print x[0], ' '
      k -= 1
      n /= x[0]
    end
  end
  puts n
end