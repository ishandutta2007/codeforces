ans=0
gets.to_i.times do
    a=gets.chomp.split.map(&:to_i).reduce(:+)
    ans = ans + 1 if a >= 2
end
puts ans